SELECT
    COUNT(f.id) fish_count,
    n.fish_name
FROM
    fish_info f
    LEFT JOIN fish_name_info n
    ON f.fish_type = n.fish_type
GROUP BY
    2
ORDER BY
    1 DESC;