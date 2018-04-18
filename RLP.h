/*
 * Copyright (c) 2016-2018, Evercoin. All Rights Reserved.
 */

#ifndef RLP_RLP_H
#define RLP_RLP_H

#include <stdbool.h>
#include <stdint.h>
#include "utils.h"

#define PB_BYTES_ARRAY_T(n) struct { pb_size_t size; pb_byte_t bytes[n]; }

typedef PB_BYTES_ARRAY_T(32) EthereumSignTx_nonce_t;
typedef PB_BYTES_ARRAY_T(32) EthereumSignTx_gas_price_t;
typedef PB_BYTES_ARRAY_T(32) EthereumSignTx_gas_limit_t;
typedef PB_BYTES_ARRAY_T(20) EthereumSignTx_to_t;
typedef PB_BYTES_ARRAY_T(32) EthereumSignTx_value_t;
typedef PB_BYTES_ARRAY_T(1024) EthereumSignTx_data_initial_chunk_t;

typedef struct _EthereumSignTx {
    EthereumSignTx_nonce_t nonce;
    EthereumSignTx_gas_price_t gas_price;
    EthereumSignTx_gas_limit_t gas_limit;
    EthereumSignTx_to_t to;
    EthereumSignTx_value_t value;
    EthereumSignTx_data_initial_chunk_t data_initial_chunk;
} EthereumSignTx;

typedef PB_BYTES_ARRAY_T(64) EthereumTxRequest_signature_r_t;
typedef PB_BYTES_ARRAY_T(64) EthereumTxRequest_signature_s_t;
typedef struct _EthereumTxRequest {
    uint32_t data_length;
    uint32_t signature_v;
    EthereumTxRequest_signature_r_t signature_r;
    EthereumTxRequest_signature_s_t signature_s;
} EthereumSig;

int wallet_encode_list(EthereumSignTx *new_msg, EthereumSig *new_tx,
                       uint64_t *rawTx);
void wallet_encode_element(pb_byte_t *bytes, pb_size_t size,
                           pb_byte_t *new_bytes, pb_size_t *new_size);
void wallet_encode_int(uint32_t singleInt, pb_byte_t *new_bytes);

#endif //RLP_RLP_H
