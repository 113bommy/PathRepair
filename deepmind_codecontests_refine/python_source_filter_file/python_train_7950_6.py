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
'''
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
        ans = ans[1:]
    ans = '$'+ans
    if ne:
        stdout.write('({})'.format(ans+flow))
    else:
        stdout.write(ans+flow)
if __name__=='__main__':
    main()

'''
#A
'''
def main():
    from sys import stdin,stdout
    n = int(stdin.readline())
    arr = list(map(int,stdin.readline().split()))
    minim = min(arr)
    my_l = []
    for i,j in enumerate(arr):
        if j==minim:
            my_l.append(i)
    my_l_ = []
    for i in range(1,len(my_l)):
        my_l_.append(my_l[i]-my_l[i-1])
    stdout.write(str(min(my_l_)))
if __name__=='__main__':
    main()
'''
#B
'''
def main():
    from sys import stdin,stdout
    n,a,b = map(int,stdin.readline().split())
    maxim = -1
    for i in range(1,n):
        maxim = max(min(a//i,b//(n-i)),maxim)
    stdout.write(str(maxim))
if __name__=='__main__':
    main()
'''
#233B
'''
def main():
    from sys import stdin,stdout
    def foo(x):
        tsum = 0
        c = x
        while c:
            tsum+=(c%10)
            c//=10
        return tsum

    N = int(stdin.readline())
    up,down = 0 , int(1e18)
    flag = False
    while up<down:
        mid = (up+down)//2
        val = foo(mid)
        val = (mid+val)*mid
        if val<N:
            up = mid
        elif val >N:
            down = mid
        else:
            flag=True
            break
        
    if flag:
        stdout.write(str(mid)+'\n')
    else:
        stdout.write('-1')
if __name__=='__main__':
    main()

def main():
    def foo(x):
        n= x
        tsum = 0
        while n:
            tsum += n%10 
            n//=10
        return x*x + tsum*x - int(1e18)
        
    import matplotlib.pyplot as plt
    y = [foo(x) for x in range(1,int(1e18)+1)]
    x = range(1,int(1e18)+1)
    print(y[:100])
    plt.plot(y,x)
    plt.show()
if __name__=='__main__':
    main()
'''
#RECTANGL
'''
def main():
    from sys import stdin,stdout
    import collections
    for _ in range(int(stdin.readline())):
        c = collections.Counter(list(map(int,stdin.readline().split())))
        flag = True
        for i in c:
            if c[i]&1:
                flag=False
        if flag:
            stdout.write('YES\n')
        else:
            stdout.write('NO\n')
if __name__=='__main__':
    main()
'''
#MAXSC
'''
def main():
    from sys import stdin,stdout
    import bisect
    for _ in range(int(stdin.readline())):
        N = int(stdin.readline())
        mat = []
        for i in range(N):
            mat.append(sorted(map(int,stdin.readline().split())))
##        print(mat)
        temp = mat[-1][-1]
        tsum = mat[-1][-1]
        flag = True
        for i in range(N-2,-1,-1):
            ind = bisect.bisect_left(mat[i],temp)-1
            if ind == -1:
                flag = False
                break
            else:
                tsum+=mat[i][ind]
        if flag:
            stdout.write(str(tsum)+'\n')
        else:
            stdout.write('-1\n')
if __name__=='__main__':
    main()
'''
#233B ********************
'''
def main():
    def rev(x):
        tsum = 0
        while x:
            tsum += x%10
            x//=10
        return tsum
    from sys import stdin,stdout
    from math import sqrt,ceil
    n = int(stdin.readline())
    for i in range(91):
        r = i*i+(n<<2)
        x = ceil(sqrt(r))
##        print(i,x)
        if x*x == r:
            num = (x-i)/2
            if num == int(num):
                if rev(num)==i:
                    stdout.write(str(int(num)))
                    return
    stdout.write('-1')
if __name__=='__main__':
    main()
'''
#228B
'''
def main():
    from sys import stdin,stdout
    na,nb = map(int,stdin.readline().split())
    A = []
    for _ in range(na):
        A.append([int(x) for x in stdin.readline().strip()])
    ma,mb = map(int,stdin.readline().split())
    B= []
    for _ in range(ma):
        B.append([int(x) for x in stdin.readline().strip()])
##    print(A)
##    print(B)
    maxim , value = -1, None 
    for x in range(1-na,ma):
        for y in range(1-nb,mb):
            tmp = 0
            for i in range(na):
                for j in range(nb):
                    if i+x > -1 and i+x <ma and i>-1 and i<na and j>-1 and j<nb and j+y > -1 and j+y <mb:
                        tmp+=A[i][j]*B[i+x][j+y]
##            print(x,y,tmp)
            if tmp > maxim:
                maxim = tmp
                value = (x,y)
##    print("MAXIM:",maxim,"VALUE:",value)
    stdout.write(str(value[0])+' '+str(value[1]))
    
if __name__=='__main__':
    main()
'''

#260B
'''
def main():
    import re , collections, datetime
    from sys import stdin,stdout

    def post_process(ans):

        datetime.MINYEAR=2013
        datetime.MAXYEAR=2015
        
        for string in ans:
            dd,mm,yyyy = map(int,string.split('-'))

            try:
                obj = datetime.date(yyyy,mm,dd)
            except:
                ans[string]=0

        return ans
    
    my_re = '(?=([0-9][0-9]-[0-1][0-9]-201[3-5]))'
    inp = stdin.readline().strip()
    ans = re.finditer(my_re,inp)
    ans = collections.Counter([m.group(1) for m in ans])
    ans = post_process(ans)
    stdout.write(ans.most_common(1)[0][0])
    
if __name__=='__main__':
    main()
'''

#214B
'''
def main():
    from sys import stdin,stdout
    N = int(stdin.readline())
    arr = list(map(int,stdin.readline().split()))
    arr.sort()
    if arr[0]!=0:
        stdout.write('-1\n')
        return
    res = sum(arr)%3
    if res:
        tmp1 = list(filter(lambda x: x%3==1,arr))
        tmp2 = list(filter(lambda x: x%3==2,arr))
        tmp3 = list(filter(lambda x: x%3==0,arr))
        
        if res&1:
            if len(tmp1):
                tmp1 = tmp1[1:]
            else:
                tmp2 = tmp2[2:]
        else:
            if len(tmp2):
                tmp2 = tmp2[1:]
            else: 
                tmp1 = tmp1[2:]

        arr = sorted(tmp1+tmp2+tmp3)

    if arr[-1]:
        for i in arr[::-1]:
            stdout.write(str(i))
        stdout.write('\n')
    else:
        stdout.write('0\n')
if __name__=='__main__':
    main()
'''
#281 B
def main():
    from sys import stdin,stdout
    from math import ceil, floor
    x,y,n = map(int,stdin.readline().split())
    ans = []

    n = min(n,y)
    ratio=x/y
    while n:
        a = floor(ratio * n)
        b = ceil(ratio * n)
        if abs(a/n-ratio) <= abs(b/n-ratio):
            ans.append((round(abs(a/n-ratio),6),n,a))
        else:
            ans.append((round(abs(b/n-ratio),6),n,b))
        n-=1
    ans.sort()
##    print(ans)
    stdout.write(str(ans[0][2])+'/'+str(ans[0][1]))
if __name__=='__main__':
    main()
