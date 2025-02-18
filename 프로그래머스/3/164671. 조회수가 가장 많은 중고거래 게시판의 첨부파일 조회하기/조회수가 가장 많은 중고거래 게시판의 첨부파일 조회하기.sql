SELECT CONCAT('/home/grep/src/', C.BOARD_ID, '/', C.FILE_ID, C.FILE_NAME, C.FILE_EXT) AS FILE_PATH
  FROM USED_GOODS_BOARD A
 INNER JOIN (
SELECT BOARD_ID
     , RANK() OVER (ORDER BY VIEWS DESC) AS VIEWS_NUM
  FROM USED_GOODS_BOARD
      ) B
    ON A.BOARD_ID = B.BOARD_ID
  INNER JOIN USED_GOODS_FILE C
    ON A.BOARD_ID = C.BOARD_ID
WHERE B.VIEWS_NUM = 1 
ORDER BY C.FILE_ID DESC
    
 