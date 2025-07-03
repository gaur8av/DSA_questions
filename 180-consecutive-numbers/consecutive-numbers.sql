SELECT DISTINCT num AS ConsecutiveNums
FROM (
    SELECT
        id,
        num,
        LAG(num, 1) OVER (ORDER BY id) AS prev1,
        LAG(num, 2) OVER (ORDER BY id) AS prev2
    FROM Logs
) sub
WHERE num = prev1 AND num = prev2;
