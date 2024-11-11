def isSubSequence(string1, string2, m, n): 
    # Base Cases 
    if m == 0:    return True
    if n == 0:    return False
  
    # If last characters of two strings are matching 
    if string1[m-1] == string2[n-1]: 
        return isSubSequence(string1, string2, m-1, n-1) 
  
    # If last characters are not matching 
    return isSubSequence(string1, string2, m, n-1)
s=input()
t=input()
if t in s or isSubSequence(s,t,len(s),len(t)):
	print("automaton")
else:	
	dic1={}
	dic2={}
	S=list(s)
	T=list(t)
	flag=0
	for x in S:
		dic1[x]=S.count(x)
	for y in T:
		dic2[y]=T.count(y)
	for z in dic2.keys():
		if z in S:
			if dic2[z]==dic1[z] and len(S)==len(T):
				flag=2
			elif dic2[z]<=dic1[z]:	
					flag=0	
			elif dic2[z]>dic1[z]:
				flag=1
				break	
		else:
			flag=1
			break

	if flag==0:
		print("both")
	if flag==2:
		print("array")
	if flag==3:
		print("automaton")		
	if flag==1:
		print("need"+" "+"tree")	

