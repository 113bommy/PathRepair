k = int(input().split()[0])
print(len(list(filter(lambda x: x+k<=5 , list(map(int , input().split())))))//3)