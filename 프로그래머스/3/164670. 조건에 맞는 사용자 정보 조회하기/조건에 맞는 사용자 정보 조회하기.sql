SELECT A.USER_ID AS USER_ID
     , A.NICKNAME AS NICKNAME
     , A.CITY || ' ' || A.STREET_ADDRESS1 || ' ' || A.STREET_ADDRESS2 AS 전체주소
     , REGEXP_REPLACE(A.TLNO, '(\d{3})(\d{4})(\d{4})', '\1-\2-\3') AS 전화번호
  FROM USED_GOODS_USER A
  INNER JOIN (
SELECT WRITER_ID
     , COUNT(1) AS CNT
  FROM USED_GOODS_BOARD
 GROUP BY WRITER_ID
      ) B
     ON A.USER_ID = B.WRITER_ID
    WHERE B.CNT >= 3
    ORDER BY A.USER_ID DESC
    