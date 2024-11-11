print([[i%j for j in range(2,i)].count(0) for i in range(1,int(input())+1,2)].count(6))
