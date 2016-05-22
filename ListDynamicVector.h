template<typename T>
class ListDynamicVector {
    private:
        class ListIterator {
            public:
                ListIterator();
                bool has_next();
                bool has_previous();
                T next();
                T previous();
                int next_index();
                int previous_index();
                void add(T element);
                void remove();
        };

    public:
        ListDynamicVector();
        ~ListDynamicVector();
        ListDynamicVector(const ListDynamicVector& that);
        ListDynamicVector& operator=(const ListDynamicVector& that);

        bool is_empty() const;
        int size() const;
        void clear();

        ListIterator iterator();
        ListIterator iterator(int index);
        T& operator[] (int index);
};
