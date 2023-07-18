// Label.h
#ifndef SDDS_LABEL_H_
#define SDDS_LABEL_H_

namespace sdds
{
    class Label
    {
        char m_frame[9];
        char* m_content;

    public:
        // constructor 
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);
        // deconstructors 
        void readLabel();
        std::ostream& printLabel() const;
    };
}

#endif