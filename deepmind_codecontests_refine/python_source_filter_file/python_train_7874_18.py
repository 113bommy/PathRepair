import sys
sys.stdout.flush()

for i in range(6):
    print(i)
    a = input()
    if (not a=="no"):
        break
if (a=="don't think so" or a=="don't touch me!" or a=="not bad" or a=="cool" or a=="great!"):
    print("normal")
else:
    print("grumpy")