select A.BOOK_ID, B.AUTHOR_NAME, DATE_FORMAT(A.PUBLISHED_DATE, '%Y-%m-%d') as PUBLISHED_DATE
  from BOOK  A
  INNER JOIN AUTHOR B
     ON A.AUTHOR_ID = B.AUTHOR_ID
 where A.CATEGORY = '경제'
  ORDER BY A.PUBLISHED_DATE