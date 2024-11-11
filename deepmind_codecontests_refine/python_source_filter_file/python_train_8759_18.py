# cook your dish here
import string
n=int(input())
s=input()
s1=string.ascii_uppercase
d={}
for i in range(len(s1)):
    d[s1[i]]=i+1
a=[]
for i in range(0,len(s)-3):
    c=0
    c+=min(abs(d[s[i]]-d['A']),26-abs(d[s[i]]-d['A']))
    c+=min(abs(d[s[i+1]]-d['C']),26-abs(d[s[i]]-d['C']))
    c+=min(abs(d[s[i+2]]-d['T']),26-abs(d[s[i]]-d['T']))
    c+=min(abs(d[s[i+3]]-d['G']),26-abs(d[s[i]]-d['G']))
    a.append(c)
print(min(a)) 