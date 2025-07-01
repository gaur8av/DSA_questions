# Write your MySQL query statement below
with duplicate as(
    select *,
    row_number() over(partition by email order by id) as 'rnk' from Person
)
select  email from duplicate
where rnk = 2