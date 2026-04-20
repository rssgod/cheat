import datetime
from typing import List, Dict, Optional

class Flight:
    def __init__(self, flight_number: str, origin: str, destination: str,
                 departure_time: datetime.datetime, duration_minutes: int):
        self.id = flight_number
        self.origin = origin
        self.destination = destination
        self.departure_time = departure_time
        self.duration = duration_minutes
        self.arrival_time = departure_time + datetime.timedelta(minutes=duration_minutes)

    def __repr__(self):
        fmt = "%H:%M"
        return f"[{self.id}: {self.origin}->{self.destination} ({self.departure_time.strftime(fmt)}-{self.arrival_time.strftime(fmt)})]"

class Aircraft:
    def __init__(self, tail_number: str, initial_location: str):
        self.tail_number = tail_number
        self.location = initial_location
        self.available_at = datetime.datetime.min
        self.schedule: List[Flight] = []

    def can_perform(self, flight: Flight, turnaround_buffer: int = 45) -> bool:
        # Check if aircraft is at the right airport
        if self.location != flight.origin:
            return False

        # Check if aircraft has enough time to 'turn' (deplane, clean, refuel)
        ready_time = self.available_at + datetime.timedelta(minutes=turnaround_buffer)
        if ready_time > flight.departure_time:
            return False

        return True

    def assign_flight(self, flight: Flight):
        self.schedule.append(flight)
        self.location = flight.destination
        self.available_at = flight.arrival_time

class AIScheduler:
    def __init__(self, fleet: List[Aircraft], turnaround_mins: int = 45):
        self.fleet = fleet
        self.turnaround_mins = turnaround_mins

    def solve(self, flight_requests: List[Flight]):
        sorted_requests = sorted(flight_requests, key=lambda x: x.departure_time)
        unassigned = []

        print(f"--- Starting AI Scheduler (Fleet Size: {len(self.fleet)}) ---")

        for req in sorted_requests:
            assigned = False

            # Search for the best available aircraft for this flight
            # A more advanced AI would use Backtracking if this fails
            for craft in self.fleet:
                if craft.can_perform(req, self.turnaround_mins):
                    craft.assign_flight(req)
                    assigned = True
                    print(f"Success: Assigned {req.id} to {craft.tail_number}")
                    break

            if not assigned:
                print(f"Warning: Could not assign {req.id} - No available aircraft at {req.origin}")
                unassigned.append(req)

        self.print_final_schedule()
        return unassigned

    def print_final_schedule(self):
        print("" + "="*50)
        print("FINAL AIRCRAFT UTILIZATION REPORT")
        print("="*50)
        for craft in self.fleet:
            sched_str = " -> ".join([f.id for f in craft.schedule])
            print(f"Tail {craft.tail_number}: {sched_str if sched_str else 'IDLE'}")
        print("="*50)

# --- Simulation Execution ---
if __name__ == "__main__":
    # 1. Setup Data
    today = datetime.datetime.now().replace(hour=6, minute=0, second=0, microsecond=0)

    # Define a set of flight legs for the day
    requests = [
        Flight("AA101", "JFK", "LAX", today + datetime.timedelta(hours=1), 360),
        Flight("AA102", "LAX", "SFO", today + datetime.timedelta(hours=8), 90),
        Flight("AA201", "JFK", "ORD", today + datetime.timedelta(hours=2), 150),
        Flight("AA202", "ORD", "DFW", today + datetime.timedelta(hours=6), 120),
        Flight("AA103", "SFO", "JFK", today + datetime.timedelta(hours=11), 300),
        Flight("AA301", "DFW", "JFK", today + datetime.timedelta(hours=9), 180),
    ]

    # 2. Setup Fleet (Initial positioning is key for AI success)
    my_fleet = [
        Aircraft("N101AA", "JFK"), # Based in New York
        Aircraft("N202AA", "JFK"), # Based in New York
    ]

    # 3. Run Scheduler
    scheduler = AIScheduler(my_fleet, turnaround_mins=60)
    failed_flights = scheduler.solve(requests)

    if failed_flights:
        print(f"Optimization Note: {len(failed_flights)} flights remained unassigned.")
        print("Action: Consider adding more aircraft or adjusting departure windows.")