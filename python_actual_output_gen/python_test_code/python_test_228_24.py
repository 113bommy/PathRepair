for _ in range(int(input())):
 a,b=map(int,input().split())
 print((b-a)//10+bool((b-a)%10))