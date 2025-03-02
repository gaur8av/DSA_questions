# Write your MySQL query statement below

select Products.product_name , SUM(Orders.unit) as Unit
from Products inner join
Orders on Products.product_id = Orders.product_id 
WHERE DATE_FORMAT(Orders.order_date, '%Y-%m') = '2020-02'
GROUP BY Products.product_id
HAVING SUM(Orders.unit) >= 100;