-- 코드를 입력하세요
SELECT A.CATEGORY
     , SUM(B.BOOK_CNT) AS TOTAL_SALES
  FROM BOOK A
 INNER JOIN (
   SELECT BOOK_ID
        , SUM(SALES) AS BOOK_CNT
     FROM BOOK_SALES 
    WHERE YEAR(SALES_DATE) = '2022'
       AND MONTH(SALES_DATE) = '01'
     GROUP BY BOOK_ID
 ) B
 ON A.BOOK_ID = B.BOOK_ID
 WHERE 1=1
  GROUP BY A.CATEGORY
  ORDER BY A.CATEGORY