from sys import stdin,stdout
input = stdin.readline
def write(n,sep="\n"):
	stdout.write(str(n))
	stdout.write(sep)
def gil():
	return list(map(int, input().split()))
	
n = int(input())
a = input().strip()
ans = ""
s = ["","","2","3","322","5","53","7","7222","7332"]
for i in a:
	ans += s[int(i)]
ans = [int(i) for i in ans]
ans.sort(reverse=True)
x = ""
for i in ans:
	x += str(i)
print(x)
