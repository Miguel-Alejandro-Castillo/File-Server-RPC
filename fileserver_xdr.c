/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "fileserver.h"

bool_t
xdr_filedata (XDR *xdrs, filedata *objp)
{
	register int32_t *buf;

	 if (!xdr_bytes (xdrs, (char **)&objp->filedata_val, (u_int *) &objp->filedata_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_filename (XDR *xdrs, filename *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, objp, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_read_1_argument (XDR *xdrs, read_1_argument *objp)
{
	 if (!xdr_filename (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->position))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->cant))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_write_1_argument (XDR *xdrs, write_1_argument *objp)
{
	 if (!xdr_filename (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_filedata (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}
