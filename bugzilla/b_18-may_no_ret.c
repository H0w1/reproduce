int advance(int mCurrent,int a) {
if ( mCurrent == 0 )
    return 0;
while( 1 )
{
    if( a > 2 )
    {
        mCurrent++;
    }
    if( mCurrent == 10 )
        break;
    if( functionReturningBool( mCurrent, a ) )
        break;
}
// warning missing return
}