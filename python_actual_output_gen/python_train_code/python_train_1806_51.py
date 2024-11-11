n = int(input()) - 10
if n <= 0:
    print(0)
else:
    freq = {1:4, 2:4, 3:4, 5:4, 6:4, 7:4, 8:4, 9:4, 9:4, 10:15, 11:1}
    try:
        print(freq[n])
    except:
        print(0)