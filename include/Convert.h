// Convert CPU double dense to GPU double dense.
GPU_Dense convert ( CPU_Dense x ) {

    GPU_Dense y(x.Size[0],x.Size[1],x.isVector);

    y.Values = x.Values;

    return y;

}

// Convert CPU float dense to GPU float dense.
GPU_Dense_f convert ( CPU_Dense_f x ) {

    GPU_Dense_f y(x.Size[0],x.Size[1],x.isVector);

    y.Values = x.Values;

    return y;

}

// Convert GPU double dense to CPU double dense.
CPU_Dense convert ( GPU_Dense x ) {

    CPU_Dense y(x.Size[0],x.Size[1],x.isVector);

    y.Values = x.Values;

    return y;

}

// Convert GPU float dense to CPU float dense.
CPU_Dense_f convert ( GPU_Dense_f x ) {

    CPU_Dense_f y(x.Size[0],x.Size[1],x.isVector);

    y.Values = x.Values;

    return y;

}

// Convert CPU double sparse to GPU double sparse.
GPU_Sparse convert ( CPU_Sparse x ) {

    GPU_Sparse y(x.Size[0],x.Size[1],x.Size[2]);

    y.Values = x.Values;
    y.J = x.J;
    
    // Convert Ib and Ie to I.
    y.I.resize(0);
    y.I.insert(y.I.begin(),x.Ib.begin(),x.Ib.end());
    y.I.resize(y.I.size() + 1);
    y.I[y.I.size() - 1] = x.Ie[x.Ie.size() - 1];

    return y;

}

// Convert CPU float sparse to GPU float sparse.
GPU_Sparse_f convert ( CPU_Sparse_f x ) {

    GPU_Sparse_f y(x.Size[0],x.Size[1],x.Size[2]);

    y.Values = x.Values;
    y.J = x.J;
    
    // Convert Ib and Ie to I.
    y.I.resize(0);
    y.I.insert(y.I.begin(),x.Ib.begin(),x.Ib.end());
    y.I.resize(y.I.size() + 1);
    y.I[y.I.size() - 1] = x.Ie[x.Ie.size() - 1];

    return y;

}

// Convert GPU double sparse to CPU double sparse.
CPU_Sparse convert ( GPU_Sparse x ) {

    CPU_Sparse y(x.Size[0],x.Size[1],x.Size[2]);

    y.Values = x.Values;
    y.J = x.J;
    
    // Convert I to Ib and Ie.
    y.Ib.resize(0);
    y.Ie.resize(0);
    y.Ib.insert(y.Ib.begin(),x.I.begin(),(x.I.end() - 1));
    y.Ie.insert(y.Ie.begin(),(x.I.begin() + 1),x.I.end());
    
    return y;

}

// Convert GPU float sparse to CPU float sparse.
CPU_Sparse_f convert ( GPU_Sparse_f x ) {

    CPU_Sparse_f y(x.Size[0],x.Size[1],x.Size[2]);

    y.Values = x.Values;
    y.J = x.J;

    // Convert I to Ib and Ie.    
    y.Ib.resize(0);
    y.Ie.resize(0);
    y.Ib.insert(y.Ib.begin(),x.I.begin(),(x.I.end() - 1));
    y.Ie.insert(y.Ie.begin(),(x.I.begin() + 1),x.I.end());
    
    return y;

}