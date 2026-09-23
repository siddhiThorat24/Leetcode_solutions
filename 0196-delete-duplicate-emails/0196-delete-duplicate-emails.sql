# Write your MySQL query statement below
DELETE u1
FROM Person u1
JOIN Person u2 
ON u1.email = u2.email
AND u1.id > u2.id;