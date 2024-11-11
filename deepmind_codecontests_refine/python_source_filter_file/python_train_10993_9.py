n=int(input())
i=1
lisa=[]
count=0
fika=["Sheldon","Leonard","Penny","Rajesh","Howard"]
# fika=["Mohit","Sunil","Sandeep","Rajesh","Rahul"]
while n>=(2**(i-1))*5 and n>0:
	n-=(2**(i-1))*5
	i+=1
while n>(2**(i-1))and n>0:
	count+=1
	n-=(2**(i-1))
print(fika[count])