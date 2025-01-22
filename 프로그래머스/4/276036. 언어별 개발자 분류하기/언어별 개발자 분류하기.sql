WITH T_DATA AS (
    SELECT A.ID 
     , A.SKILL_CODE
     , B.NAME
     , B.CATEGORY
     , A.EMAIL
     , CASE WHEN A.SKILL_CODE & B.CODE = B.CODE THEN '2'
            ELSE '1'
        END AS INCLUDEYN
  FROM DEVELOPERS  A
     , SKILLCODES  B
)
SELECT MIN(X.GRADE) AS GRADE
     , X.ID
     , MAX(X.EMAIL) AS EMAIL
  FROM (
SELECT CASE WHEN A.NAME = 'Python ' AND A.NAME_IN = '2' AND B.CATEGORY = 'Front End' AND B.CATEGORY_IN = '2'
                 THEN 'A'
            WHEN A.NAME = 'C#' AND A.NAME_IN = '2' THEN 'B'
            WHEN B.CATEGORY = 'Front End' AND B.CATEGORY_IN = '2' THEN 'C'
            ELSE 'D'
        END AS GRADE
     , A.ID
     , A.EMAIL
  FROM (
       SELECT Y.ID
            , Y.NAME
            , MAX(Y.INCLUDEYN) AS NAME_IN
            , MAX(Y.EMAIL) AS EMAIL
         FROM T_DATA Y
        GROUP BY Y.ID, Y.NAME
       ) A
 INNER JOIN (
      SELECT T.ID
     , T.CATEGORY
     , MAX(T.INCLUDEYN) AS CATEGORY_IN
  FROM T_DATA T
 GROUP BY T.ID, T.CATEGORY
 ) B
 ON A.ID = B.ID
      ) X
     WHERE X.GRADE <> 'D'
    GROUP BY X.ID
    ORDER BY MIN(X.GRADE), X.ID 