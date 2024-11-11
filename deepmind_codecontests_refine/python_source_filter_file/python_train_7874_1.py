for i in range(10):
    print(i)
    b = input()
    if "don't even" in b or 'terrible' in b or 'serios' in b or 'worse' in b or 'go die' in b or 'way' in b:
        print("grumpy")
        break
    elif b != 'no':
        print('normal')
        break
    elif i > 2:
        print('normal')
        break