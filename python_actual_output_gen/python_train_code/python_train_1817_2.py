n = int(input())
s = input()
index1 = s.find('R')
index2 = s.find('L')
if index1==-1:
    count = 0
    for ele in s:
        if ele == 'L':
            count+=1
    index1 = index2
    index2 = index1+count-1
    print(index2+1,index1-1)
elif index2==-1:
    count = 0
    for ele in s:
        if ele == 'R':
            count+=1
    
    index2 = index1 +count+1
    print(index1+1,index2)
else:
    print(index1+1,index2)

#print(index1+1,index2)