w = input()
print('Yes') if sum([int(w.count(chr(x))%2) for x in range(65,65+26)])==0 else print('No')