-- 11. Titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated
SELECT m.title FROM movies m
JOIN stars s ON m.id=s.movie_id
JOIN people p ON s.person_id =p.id
JOIN ratings r ON m.id=r.movie_id
WHERE p.name = 'Chadwick Boseman'
ORDER BY r.rating  DESC
LIMIT 5;
