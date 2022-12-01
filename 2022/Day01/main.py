# import array as arr

def ex01(lines):
    max = 0
    num = 0
    for line in lines:
        if (len(line) == 1):
            if (max < num):
                max = num
            num = 0
        else:
            num += int(line.rstrip())
    print("Max: ", max)


def ex02(lines):
    num = 0
    numArray = list()
    for line in lines:
        if (len(line) == 1):
            numArray.append(num)
            num = 0
        else:
            num += int(line.rstrip())
    numArray.sort(reverse=True)
    print("Total: ", numArray[0] + numArray[1] + numArray[2])


def __main__():
    input = open("input.txt", 'r')
    lines = input.readlines()
    ex01(lines)
    ex02(lines)


__main__()
