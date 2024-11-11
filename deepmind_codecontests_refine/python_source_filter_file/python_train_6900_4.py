'''
def main():
	from sys import stdin,stdout
if __name__=='__main__':
	main()
'''
#349B
'''
def main():
	from sys import stdin,stdout
	N = int(stdin.readline())
	arr = list(map(int,stdin.readline().split()))
	div = []
	for i in arr:
		div.append(N//i)
	maxim = 0
	maxindex = -1
	for i in range(9):
		if div[i] >maxim:
			maxim = div[i]
			maxindex = i
	if maxindex > -1:
		ans = [ (maxindex+1) for i in range(maxim)]
		N= N%arr[maxindex]
		#print(N)
		i = 0
		while i<maxim:
			#print('i=',i,'N=',N)
			for j in range(8,maxindex,-1):
				#print('j=',j,'diff=',arr[j]-arr[ans[i]-1])
				if arr[j]-arr[ans[i]-1] <=N:
					N -= arr[j]-arr[ans[i]-1]
					ans[i] = j+1
					break
			i+=1
		for i in ans:
			stdout.write(str(i))
	else:
		stdout.write('-1\n')
if __name__=='__main__':
	main()
'''
#234B Input and Output
'''
def main():
	from sys import stdin,stdout
	import collections
	with open('input.txt','r') as ip:
		N,K = map(int,ip.readline().split())
		arr = list(map(int,ip.readline().split()))
	mydict = collections.defaultdict(set)
	for i in range(len(arr)):
		mydict[arr[i]].add(i+1)
	ans = []
	i=0
	while K>0:
		for it in mydict[sorted(mydict.keys(),reverse=True)[i]]:
			ans.append(it)
			K-=1
			if K<1:
				break
		minim=i
		i+=1
	with open('output.txt','w') as out:
		out.write(str(sorted(mydict.keys(),reverse=True)[minim])+'\n')
		ans=' '.join(str(x) for x in ans)
		out.write(ans+'\n')		
if __name__=='__main__':
	main()
'''
#151B
'''
def main():
	from sys import stdin,stdout
	import collections
	names = collections.defaultdict(list)
	counter = 0
	order = {}
	for i in range(int(stdin.readline())):
		n,ns = stdin.readline().split()
		names[ns]=[0,0,0]
		order[ns]=counter
		counter+=1
		n=int(n)
		while n:
			ip=stdin.readline().strip()
			ip=ip.replace('-','')
			#test for taxi
			flag=True
			for i in range(1,6):
				if ip[i]!=ip[0]:
					flag=False
					break
			if flag:
				names[ns][0]+=1
				n-=1
				continue
			#test for pizza
			flag = True
			for i in range(1,6):
				if int(ip[i])>=int(ip[i-1]):
					flag =False
					break
			if flag:
				names[ns][1]+=1

			else:
				names[ns][2]+=1
			n-=1
	#print(names)
	#for all girls
	t=-1
	p=-1
	g=-1
	for i in names:
		t=max(t,names[i][0])
		p = max(p, names[i][1])
		g = max(g, names[i][2])

	taxi=list(filter(lambda x: names[x][0]==t, names.keys()))
	pizza = list(filter(lambda x: names[x][1] == p, names.keys()))
	girls = list(filter(lambda x: names[x][2] == g, names.keys()))

	pizza.sort(key= lambda x: order[x])
	taxi.sort(key= lambda x: order[x])	
	girls.sort(key= lambda x: order[x])

	print('If you want to call a taxi, you should call:',', '.join(x for x in taxi),end='.\n')
	print('If you want to order a pizza, you should call:', ', '.join(x for x in pizza),end='.\n')
	print('If you want to go to a cafe with a wonderful girl, you should call:', ', '.join(x for x in girls),end='.\n')

if __name__=='__main__':
	main()
'''
#SQUADRUN Q2
'''
def LCMgen(a):
	import math
	lcm = a[0]
	for i in range(1,len(a)):
		g = math.gcd(lcm,a[i])
		lcm = (lcm*a[i])//g
	return lcm	
	
def main():
	from sys import stdin,stdout
	import collections
	import math
	N,W = map(int,stdin.readline().split())
	counter = collections.Counter(map(int,stdin.readline().split()))
	lcm = LCMgen(list(counter.keys()))
	W*=lcm
	div = 0
	for i in counter:
		div+=counter[i]*(lcm//i)
	ans = math.ceil(W/div)
	stdout.write(str(ans))
if __name__=='__main__':
	main()
'''
#143B
def main():
    from sys import stdin,stdout
    ip = stdin.readline().strip()
    inte = None
    flow = None
    for i,j in enumerate(ip):
        if j=='.':
            flow = ip[i:]
            inte = ip[:i]
            break
    if flow == None:
        flow = '.00'
        inte = ip
    else:
        if len(flow)==2:
            flow+='0'
        else:
            flow = flow[:3]
    ne = False
    if ip[0]=='-':
        ne = True
    if ne:
        inte = inte[1:]
    inte = inte[::-1]
    ans =''
    for i,j in enumerate(inte):
        ans += j
        if i%3 == 2:
            ans+=','
    ans = ans[::-1]
    if ans[0]==',':
        ans = ans[1:0]
    ans = '$'+ans
    if ne:
        stdout.write('({})'.format(ans+flow))
    else:
        stdout.write(ans+flow)
if __name__=='__main__':
    main()

