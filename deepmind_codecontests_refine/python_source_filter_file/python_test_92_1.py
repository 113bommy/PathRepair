
test_case = int(input())

def make_equal(keep):
    while keep.count('ab') != keep.count('ba'):
        if keep.count('ab') > keep.count('ba'):
            keep = keep.replace('ab','bb',1)
        else :
            keep = keep.replace('ba','bb',1)
    return  keep

while test_case :
    string = input()
    if string.count('ab') == string.count('ba'):
        print(f"{string}")
    else :
        print(make_equal(string))
    test_case -= 1
