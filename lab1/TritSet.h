#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_map>

enum Trit
{
    False,               // 00
    Unknown,			 // 01
    True				 // 11
};

class TritSet{

public:

    class Reference
    {
    public:
        Reference(TritSet &, size_t);
        ~Reference();
        Reference& operator=(Trit);
        Reference& operator=(Reference const&);
        Trit getTrit() const;
        size_t getpos() const;
        operator Trit() const;

        friend bool operator==(Trit const & a, Reference const & b);
        friend bool operator==(Reference const & b, Trit const & a);
        friend bool operator==(Reference const & a, Reference const & b);
    private:
        size_t getIndInBlock() const;
        const size_t pos;
        // static Block getMask(size_t);
        TritSet & tritset;

    };


    TritSet(size_t);
    TritSet();
    TritSet( TritSet const &);
    ~TritSet();
    Trit getTrit(size_t) const;
    int setTrit(Trit, size_t);
    size_t capacity();
    size_t length();

    TritSet & operator=(TritSet const &);
    Reference operator[](size_t);
    Trit operator[](size_t) const;
    void setLength();
    void setLength(size_t);
    void resize(size_t);
    void shrink();
    size_t cardinality(Trit);
    std::unordered_map< Trit, int, std::hash<int> > cardinality();
    static Trit convert(int);
    static int convert(Trit);
    static int emply_cell();
    void trim(size_t);
    friend TritSet operator&(TritSet const & a, TritSet const & b);
    friend TritSet operator|(TritSet const & a, TritSet const & b);
    friend TritSet operator~(TritSet const & a);


private:
    size_t size_;
    const size_t size_orig_;
    size_t logical_length_=0;
    size_t index_size_=size_*16;
    int last_set;
    int32_t *trits;




};