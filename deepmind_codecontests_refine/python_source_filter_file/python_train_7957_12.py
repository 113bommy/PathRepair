def num(str):
    alphabet = "abcdefghijklmnopqrstvuwxyz"

def summ(array, k, str):
    summ = 0
    alphabet = "abcdefghijklmnopqrstvuwxyz"
    for i in range(len(str)):
        order = 1
        for j in range(len(alphabet)):
            if alphabet[j] == str[i] :
                order = j
        summ+=array[order]*(i+1)
    max = 0
    for i in range(len(array)):
        if(array[i]>max):
            max = array[i]
    for i in range(k):
        summ+=max*(len(str)+i+1)
    return summ

str = input()
k = int(input())
array = input().split(" ")
newar = []
for i in range(len(array)):
     newar.append(int(array[i]))
print(summ(newar, k, str))