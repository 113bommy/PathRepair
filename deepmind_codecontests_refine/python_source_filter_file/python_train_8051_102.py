# from flask import Flask, render_template, g, request
# from werkzeug.security import generate_password_hash, check_password_hash
# print (generate_password_hash("Dont-reveal-my-secret-passw@rd", "sha256"))
# print(check_password_hash('sha256$U0DSLGOH$65bc158d00b0968ee8b9e9ad23c5aa5c2ac78090ba0212cfda02a7544f7cea55', "Dont-reveal-my-secret-passw@rd"))

# a=int(input())
# b=int(input())
# c=int(input())
# d=int(input())
# e=int(input())

# mylist1=[]
# mylist2=[]
# mylist3=[]
# mylist4=[]
# mylist5=[]

# for i in range(1,e+1):
# 	if i%a==0:
# 		mylist1.append(i)
# 	if i%b==0:
# 		mylist2.append(i)
# 	if i%c==0:
# 		mylist3.append(i)
# 	if i%d==0:
# 		mylist4.append(i)
# all_lists=mylist1+mylist2+mylist3+mylist4
# f=set(all_lists)
# print(e-(e-len(f)))


n=int(input())
mylist=[]
m=input().split()
for i in m:
	mylist.append(int(i))
print(sum(mylist)/3)