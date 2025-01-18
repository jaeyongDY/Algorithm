select COUNT(1) AS COUNT
  from ECOLI_DATA A
 WHERE A.GENOTYPE & 2 <> 2
   AND (A.GENOTYPE & 1 = 1
       OR A.GENOTYPE & 4 = 4
       OR A.GENOTYPE & 5 = 5
        )
