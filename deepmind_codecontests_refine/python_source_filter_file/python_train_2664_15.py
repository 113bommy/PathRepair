seq = "ROYGBIV"
n = int(input())

x = n//7
n = n%7

answer = seq*x
if n==1:
    answer += "G"
elif n==2:
    answer+="GB"
elif n==3:
    answer += "GBI"
elif n==4:
    answer += "GBIV"
elif n==5:
    answer += "GBIVG"
elif n==6:
    answer += "GBIVG"

print(answer)