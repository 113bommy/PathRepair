#l = ['.']
lettre = ['ABC','ACB','BCA','BAC','CAB','CBA','CBAB','CCABBCBCCBC','ACCCCBBB', 'CAACCB' ,'BCCAB','BABAAAACCBCB','BCAABBC','BBCACCC','BAABABAACCAC','ACCBBCA','ABBAACC','BAABABABBCBB','CCCAABBCCACAC','ABACAACC','BBBCA','CAACCBBA','BABCCBCCB','AABAAC','CACCBAA','ABBABAB','CBAABABCCC','ABCBCBBAA','ABABB','AABABBCCAA'  ]
k =0
ch = input ()
for i in ch:
    n=ch.split('.')
#print (n)
for j in n :
    if j in lettre :
        k=k+1

print ("NO") if (k==0) else print ("YES")