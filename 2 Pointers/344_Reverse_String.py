class Solution:
    def reverseString(self, s):
        i = 0
        j = len(s) - 1

        while i < j:
            tmp = s[i]
            s[i] = s[j]
            s[j] = tmp

            i +=1
            j -=1


if __name__ == "__main__":
    sol = Solution()
    
    s = ['h','e','l','l','o']
    # s = ['H', 'a', 'n', 'n', 'a', 'h']

    sol.reverseString(s)

    for c in s:
        print(c, end=" ")       # Output: o l l e h
    print()

