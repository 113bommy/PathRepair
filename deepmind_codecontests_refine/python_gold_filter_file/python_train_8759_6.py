n=int(input())
s=input()
m=104
count=0
for i in range(0,n-3):
	count+=(min(abs(ord(s[i])-65),abs(65-ord(s[i])-26),abs(65-ord(s[i])+26)))
	#print (count)
	count+=(min(abs(ord(s[i+1])-67),abs(67-ord(s[i+1])-26),abs(67-ord(s[i+1])+26)))
	#print (count)
	count+=(min(abs(ord(s[i+2])-84),abs(84-ord(s[i+2])-26),abs(84-ord(s[i+2])+26)))
	#print (count)
	count+=(min(abs(ord(s[i+3])-71),abs(71-ord(s[i+3])-26),abs(71-ord(s[i+3])+26)))
	if count<m:
		m=count
	count=0
print (m)