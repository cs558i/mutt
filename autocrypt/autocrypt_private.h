/*
 * Copyright (C) 2019 Kevin J. McCarthy <kevin@8t8.us>
 *
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program; if not, write to the Free Software
 *     Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef _AUTOCRYPT_PRIVATE_H
#define _AUTOCRYPT_PRIVATE_H 1

#include <sqlite3.h>

int mutt_autocrypt_account_init (void);

int mutt_autocrypt_db_init (int can_create);
void mutt_autocrypt_db_close (void);

AUTOCRYPT_ACCOUNT *mutt_autocrypt_db_account_new (void);
void mutt_autocrypt_db_account_free (AUTOCRYPT_ACCOUNT **account);
int mutt_autocrypt_db_account_get (ADDRESS *addr, AUTOCRYPT_ACCOUNT **account);
int mutt_autocrypt_db_account_insert (ADDRESS *addr, const char *keyid,
                                      const char *keydata, int prefer_encrypt);

AUTOCRYPT_PEER *mutt_autocrypt_db_peer_new (void);
void mutt_autocrypt_db_peer_free (AUTOCRYPT_PEER **peer);
int mutt_autocrypt_db_peer_get (ADDRESS *addr, AUTOCRYPT_PEER **peer);
int mutt_autocrypt_db_peer_insert (ADDRESS *addr, AUTOCRYPT_PEER *peer);
int mutt_autocrypt_db_peer_update (ADDRESS *addr, AUTOCRYPT_PEER *peer);

AUTOCRYPT_PEER_HISTORY *mutt_autocrypt_db_peer_history_new (void);
void mutt_autocrypt_db_peer_history_free (AUTOCRYPT_PEER_HISTORY **peerhist);
int mutt_autocrypt_db_peer_history_insert (ADDRESS *addr, AUTOCRYPT_PEER_HISTORY *peerhist);

int mutt_autocrypt_schema_init (void);
int mutt_autocrypt_schema_update (void);

int mutt_autocrypt_gpgme_init (void);
int mutt_autocrypt_gpgme_create_key (ADDRESS *addr, BUFFER *keyid, BUFFER *keydata);
int mutt_autocrypt_gpgme_import_key (const char *keydata, BUFFER *keyid);

#endif
