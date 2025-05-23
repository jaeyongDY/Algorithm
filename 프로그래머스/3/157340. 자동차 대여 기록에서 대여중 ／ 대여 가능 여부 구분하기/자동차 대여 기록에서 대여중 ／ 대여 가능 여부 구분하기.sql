WITH CAR_INFO AS (
SELECT CAR_ID
     , MAX(CASE WHEN START_DATE <= '2022-10-16' AND END_DATE >= '2022-10-16' THEN 1 ELSE 0 END) AS M
  FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
 GROUP BY CAR_ID
 ) 
 SELECT X.CAR_ID
      , CASE WHEN X.M = 1 THEN '대여중' ELSE '대여 가능' END AS AVAILABILITY
   FROM CAR_INFO X
  ORDER BY X.CAR_ID DESC