/*
 * Copyright (C) 2014, Martin Abente Lahaye - tch@sugarlabs.org
 * Copyright (C) 2025, Chihurumnaya Ibiam   - ibiam@sugarlabs.org
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "sugar-clipboard.h"

/**
 * sugar_clipboard_set_with_data:
 * @clipboard: a #GdkClipboard
 * @mime_type: mime type of data.
 * @user_data: user data to set as on the clipboard.
 *
 * Sets a new content provider on clipboard.
 *
 * The clipboard will claim the GdkDisplay‘s resources and advertise
 * these new contents to other applications.
 * In the rare case of a failure, this function will return FALSE.
 * The clipboard will then continue reporting its old contents and ignore provider.
 * If the contents are read by either an external application or the clipboard‘s
 * read functions, clipboard will select the best format to transfer the
 * contents and then request that format from provider.
 *
 * Return value: %TRUE if setting the clipboard data succeeded.
**/

gboolean
sugar_clipboard_set_with_data (GdkClipboard *clipboard,
                               const gchar  *mime_type,
                               gpointer      user_data)
{
    GBytes *data = g_bytes_new_take (user_data, sizeof(user_data));
    GdkContentProvider *provider = gdk_content_provider_new_for_bytes (mime_type, data);

    return gdk_clipboard_set_content (clipboard,
				      provider);
}
