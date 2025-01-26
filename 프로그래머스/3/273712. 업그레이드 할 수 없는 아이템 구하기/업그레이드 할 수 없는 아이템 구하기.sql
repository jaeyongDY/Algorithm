
SELECT A.ITEM_ID
     , A.ITEM_NAME
     , A.RARITY
  FROM ITEM_INFO A
  WHERE NOT EXISTS (
                SELECT 1
                  FROM ITEM_TREE  X
                 WHERE X.PARENT_ITEM_ID = A.ITEM_ID
                   AND X.PARENT_ITEM_ID IS NOT NULL
                   )
    ORDER BY A.ITEM_ID  DESC