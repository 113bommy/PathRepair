l1 = list(input())
l2 = list(input())
l3 = list(input())
dict1 = {'A':0,'B':0,'C':0}
if l1[1] == '>':
    dict1[l1[0]]+=1
    dict1[l1[2]]-=1
else:
    dict1[l1[0]]-=1
    dict1[l1[2]]+=1
    
if l2[1] == '>':
    dict1[l2[0]]+=1
    dict1[l2[2]]-=1
else:
    dict1[l2[0]]-=1
    dict1[l2[2]]+=1
    
if l3[1] == '>':
    dict1[l3[0]]+=1
    dict1[l3[2]]-=1
else:
    dict1[l3[0]]-=1
    dict1[l3[2]]+=1
l4 = list(dict1.items())
l4.sort(key = lambda x:x[1])
if l4[0][1] == -2 and l4[1][1] == 0 and l4[2][1] == 2:
    #   print(l4)
    
    print(l4[0][0]+l4[1][0]+l4[2][0])
else:
    print('Impossible')