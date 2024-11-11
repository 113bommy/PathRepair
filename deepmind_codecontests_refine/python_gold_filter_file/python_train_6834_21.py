# Imports


##############################################
# Input
# hint: for standard i/o use input() and print()
#       examples:
#           a, b = map(lambda x: int(x), input().split())
#           print(res)
# hint2: for file i/o use input.txt and output.txt
#       examples:
#           fin = open('input.txt', 'r')
#           line = fin.readline()
#           a, b = map(lambda x: int(x), line.split())
#
#           fout = open('output.txt', 'w')
#           fout.write(str(result))
#           fout.close()


k = int(input())



##############################################
# Main code

if k > 18*2:
    print(-1)
else:
    res = ''
    res += '8' * (k//2)
    if k%2:
        res += '9'
    print(res)

# FUCK




