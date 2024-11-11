
def replace_symb(n, word1, word2):
    '''Function takes the input, zips letters, finds non-ordinary pairs and places/removes them from stack'''
    letter_pairs = list(zip(word1, word2))
    stack = []
    count = 0
    for pair in letter_pairs:
        if pair[0] != pair[1]:
            count += 1
            if pair in stack:
                stack.remove(pair)
            else:
                stack.append(pair)
    print('No' if bool(stack) or count > 4*n-1 else 'Yes')

if __name__ == '__main__':
    for i in range(int(input())):
        replace_symb(int(input()), input(), input())
