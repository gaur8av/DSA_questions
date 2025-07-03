WITH flags AS (
    SELECT *,
           CASE
               WHEN num = LAG(num) OVER (ORDER BY id) THEN 0
               ELSE 1
           END AS is_new_group
    FROM Logs
),

grouped AS (
    SELECT *,
           SUM(is_new_group) OVER (ORDER BY id) AS group_num
    FROM flags
),

group_counts AS (
    SELECT
        group_num,
        num,
        COUNT(*) AS cnt
    FROM grouped
    GROUP BY group_num, num
)

SELECT DISTINCT num AS ConsecutiveNums
FROM group_counts
WHERE cnt >= 3;


