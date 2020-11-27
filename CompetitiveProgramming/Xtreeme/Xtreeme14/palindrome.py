# Python program 
import sys 

def printSubStr(st, low, high) : 
    sys.stdout.write(st[low : high + 1]) 
    sys.stdout.flush() 
    return '' 
  
def longestPalSubstr(st) : 
    n = len(st) # get length of input string 
  
    # table[i][j] will be false if substring  
    # str[i..j] is not palindrome. Else  
    # table[i][j] will be true 
    table = [[0 for x in range(n)] for y 
                          in range(n)]  
      
    # All substrings of length 1 are 
    # palindromes 
    maxLength = 1
    i = 0
    while (i < n) : 
        table[i][i] = True
        i = i + 1
      
    # check for sub-string of length 2. 
    start = 0
    i = 0
    while i < n - 1 : 
        if (st[i] == st[i + 1]) : 
            table[i][i + 1] = True
            start = i 
            maxLength = 2
        i = i + 1
      
    # Check for lengths greater than 2.  
    # k is length of substring 
    k = 3
    while k <= n : 
        # Fix the starting index 
        i = 0
        while i < (n - k + 1) : 
              
            # Get the ending index of  
            # substring from starting  
            # index i and length k 
            j = i + k - 1
      
            # checking for sub-string from 
            # ith index to jth index iff  
            # st[i + 1] to st[(j-1)] is a  
            # palindrome 
            if (table[i + 1][j - 1] and 
                      st[i] == st[j]) : 
                table[i][j] = True
      
                if (k > maxLength) : 
                    start = i 
                    maxLength = k 
            i = i + 1
        k = k + 1
  
    return maxLength,start,start+maxLength-1 # return length of LPS 
  
  
N = int(input())
def rec(curr_str,update_l):
    if curr_str == "" or len(curr_str) == 1:
        update_l.append(1) 
        return  
    
    l,start2,end = longestPalSubstr(curr_str)
    update_l.append(l) 
    rec(curr_str[:start2],update_l)
    rec(curr_str[end+1:],update_l)  

greater_l = 0
def isPalindrome(s):
    return s == s[::-1]

for tc in range(N):
    curr = input()
    upd_l = [0]
    rec(curr,upd_l)
    if isPalindrome(curr): 
        print(len(curr)-1)
    else:
        upd_l.sort() # de menor a mayor
        print(upd_l[-2]+upd_l[-1])

        
