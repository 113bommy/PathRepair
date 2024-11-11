a,s,d,f=map(int,input().split())
a+=s;d+=f
print("Right"if a<d else"Left"if a>d else"Balanced")
