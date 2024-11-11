a,s,d,f=map(int,input().split())
a+=s;d+=f
print("Right"if a<s else"Left"if a>s else"Balanced")