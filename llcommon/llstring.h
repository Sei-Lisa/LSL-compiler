#ifndef _LLSTRING__H_
#define _LLSTRING__H_

inline std::string ll_safe_string(const char* in)
{
        if(in) return std::string(in);
        return std::string();
}

#endif /* _LLSTRING__H_ */
