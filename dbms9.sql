// 1. Switch to database
use abc10;

// 2. Create collection (optional)
db.createCollection("STUDENT");

// 3. Insert documents
db.STUDENT.insertMany([
{
    Roll_no: 10,
    Student_Name: 'Amit',
    Age: 21,
    Branch: 'CSE',
    Address: { City: 'Pune', State: 'Maharashtra' },
    Hobbies: ['Drawing', 'Chess']
},
{
    Roll_no: 11,
    Student_Name: 'Koustubh',
    Age: 21,
    Branch: 'CSE',
    Address: { City: 'Solapur', State: 'Maharashtra' },
    Hobbies: ['Swimming', 'Chess']
},
{
    Roll_no: 12,
    Student_Name: 'Madhav',
    Age: 21,
    Branch: 'ECE',
    Address: { City: 'Kolhapur', State: 'Maharashtra' },
    Hobbies: ['Swimming', 'Drawing']
},
{
    Roll_no: 13,
    Student_Name: 'Govind',
    Age: 21,
    Branch: 'ECE',
    Address: { City: 'Udupi', State: 'Karnataka' },
    Hobbies: ['Playing', 'Drawing']
},
{
    Roll_no: 14,
    Student_Name: 'Harsh',
    Age: 21,
    Branch: 'CIVIL',
    Address: { City: 'Hampi', State: 'Karnataka' },
    Hobbies: ['Singing', 'Drawing']
},
{
    Roll_no: 15,
    Student_Name: 'Keshav',
    Age: 20,
    Branch: 'CIVIL',
    Address: { City: 'Coorg', State: 'Karnataka' },
    Hobbies: ['Singing', 'Swimming']
}
]);

// 4. Queries and Operations

// Display all documents
db.STUDENT.find().pretty();

// Find students younger than 21
db.STUDENT.find({ Age: { $lt: 21 } }).pretty();

// Sort by name ascending
db.STUDENT.find().sort({ Student_Name: 1 }).pretty();

// Update Branch for Roll No 14
db.STUDENT.updateOne(
    { Roll_no: 14 },
    { $set: { Branch: "CSE" } }
);

// Delete Roll No 13
db.STUDENT.deleteOne({ Roll_no: 13 });

// Count documents
db.STUDENT.countDocuments();

// Regex search (Names starting with 'A')
db.STUDENT.find({
    Student_Name: { $regex: "^A", $options: "i" }
}).pretty();

// Projection (Show only Name, hide ID)
db.STUDENT.find(
    { "Address.City": "Pune" },
    { Student_Name: 1, _id: 0 }
);

// Distinct Cities
db.STUDENT.distinct("Address.City");