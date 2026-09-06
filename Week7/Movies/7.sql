-- 7. All movies and ratings from 2010, in decreasing order by rating (alphabetical for those with same rating)
SELECT m.title, r.rating FROM movies m
JOIN ratings r ON m.id=r.movie_id
WHERE m.year = 2010
ORDER BY r.rating DESC, m.title ASC;
