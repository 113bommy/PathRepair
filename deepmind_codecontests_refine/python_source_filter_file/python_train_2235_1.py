from sys import stdin
inf=stdin
#inf=open("data1.txt",'rt')

n,m=inf.readline().split(" ")
t=int(max(max(n),max(m)))+1
ans=int(n,t+1)+int(m,t+1)

t1=t
val=1
while ans//t1>0:
	val+=1
	t1*=t

print(val)

#n=int(inf.readline())
#s=inf.readline()
# s="bacabcab"
# changed=False
# while not changed:
# 	print(s)
# 	changed=True
# 	i=0
# 	ll=len(s)
# 	while(i+1<ll and ord(s[i])!=ord(s[i+1])+1):
# 		i+=1
# 	j=i+1
# 	while(j+1<ll and ord(s[j])==ord(s[j+1])+1):
# 		j+=1

# 	if(i+1!=ll):
# 		s=s[:i]+s[j+1:]
# 		changed=False
# 	print(i,j,s[:i],s[j+1:])

# 	i=0
# 	ll=len(s)
# 	while(i+1<ll and ord(s[i])!=ord(s[i+1])-1):
# 		i+=1
# 	j=i+1
# 	while(j+1<ll and ord(s[j])==ord(s[j+1])-1):
# 		j+=1
# 	if(i+1!=ll):
# 		s=s[:i+1]+s[j+2:]
# 		changed=False
# 	print(i,j,s[:i+1],s[j+2:])

# print(len(s))
# for i in dicti:
# 	temp=0
# 	for j in helper:
# 		if(j[0]<=i[0] and j[1]<=i[1]):
# 			temp+=(i[0]-j[0]+1)*(i[1]-j[1]+1)
# 		if(j[1]<=i[0] and j[0]<=i[1] and j[0]!=j[1]):
# 			temp+=(i[0]-j[1]+1)*(i[1]-j[0]+1)
# 	count+=temp*dicti[i]



# def all_partitions(string):
#     for cutpoints in range(1 << (len(string)-1)):
#         result = []
#         lastcut = 0
#         for i in range(len(string)-1):
#             if (1<<i) & cutpoints != 0:
#                 result.append(string[lastcut:(i+1)])
#                 lastcut = i+1
#         result.append(string[lastcut:])
#         yield result

# maxyet=0
# store={'h': -6, 'e': -7, 'l': -8, 'o': 3, 'he': 3, 'hel': -3, 'el': 0, 'hell': 6, 'ell': -5, 'll': 10, 'hello': -3, 'ello': -8, 'llo': 9, 'lo': -6}

# def quality(stri):
# 	return store[stri]

# for partition in all_partitions("hel"):
#     temp=0
#     for i in partition:
#     	temp+=quality(i)
#     if(temp>maxyet):
#     	print(partition)
#     	maxyet=temp

# print(maxyet)