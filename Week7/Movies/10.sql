-- 10. Names of all directors who have directed a movie that got a rating of at least 9.0
SELECT DISTINCT p.name FROM people p
JOIN directors d on p.id=d.person_id
JOIN movies m on d.movie_id=m.id
JOIN ratings r ON m.id=r.movie_id
WHERE r.rating >= 9.0;
